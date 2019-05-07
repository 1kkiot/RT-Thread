#include "uartcmd.h"
struct stm32_uart
{
    UART_HandleTypeDef huart;
    IRQn_Type irq;
};
static rt_err_t stm32_configure(struct rt_serial_device *serial, struct serial_configure *cfg)
{
    struct stm32_uart *uart;
    RT_ASSERT(serial != RT_NULL);
    RT_ASSERT(cfg != RT_NULL);
    uart = (struct stm32_uart *)serial->parent.user_data;
    uart->huart.Init.BaudRate   = cfg->baud_rate;
    uart->huart.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
    uart->huart.Init.Mode       = UART_MODE_TX_RX;
    uart->huart.Init.OverSampling = UART_OVERSAMPLING_16;
    switch (cfg->data_bits)
    {
    case DATA_BITS_8:
        uart->huart.Init.WordLength = UART_WORDLENGTH_8B;
        break;
    case DATA_BITS_9:
        uart->huart.Init.WordLength = UART_WORDLENGTH_9B;
        break;
    default:
        uart->huart.Init.WordLength = UART_WORDLENGTH_8B;
        break;
    }
    switch (cfg->stop_bits)
    {
    case STOP_BITS_1:
        uart->huart.Init.StopBits   = UART_STOPBITS_1;
        break;
    case STOP_BITS_2:
        uart->huart.Init.StopBits   = UART_STOPBITS_2;
        break;
    default:
        uart->huart.Init.StopBits   = UART_STOPBITS_1;
        break;
    }
    switch (cfg->parity)
    {
    case PARITY_NONE:
        uart->huart.Init.Parity     = UART_PARITY_NONE;
        break;
    case PARITY_ODD:
        uart->huart.Init.Parity     = UART_PARITY_ODD;
        break;
    case PARITY_EVEN:
        uart->huart.Init.Parity     = UART_PARITY_EVEN;
        break;
    default:
        uart->huart.Init.Parity     = UART_PARITY_NONE;
        break;
    }
    if (HAL_UART_Init(&uart->huart) != HAL_OK)
    {
        return RT_ERROR;
    }
    return RT_EOK;
}
static rt_err_t stm32_control(struct rt_serial_device *serial, int cmd, void *arg)
{
    struct stm32_uart *uart;
    RT_ASSERT(serial != RT_NULL);
    uart = (struct stm32_uart *)serial->parent.user_data;
    switch (cmd)
    {
    /* disable interrupt */
    case RT_DEVICE_CTRL_CLR_INT:
        /* disable rx irq */
        NVIC_DisableIRQ(uart->irq);
        /* disable interrupt */
        __HAL_UART_DISABLE_IT(&uart->huart, USART_IT_RXNE);
        break;
    /* enable interrupt */
    case RT_DEVICE_CTRL_SET_INT:
        /* enable rx irq */
        NVIC_EnableIRQ(uart->irq);
        /* enable interrupt */
        __HAL_UART_ENABLE_IT(&uart->huart, USART_IT_RXNE);
        break;
    }
    return RT_EOK;
}
static int stm32_putc(struct rt_serial_device *serial, char c)
{
    struct stm32_uart *uart;
    RT_ASSERT(serial != RT_NULL);
    uart = (struct stm32_uart *)serial->parent.user_data;
    __HAL_UART_CLEAR_FLAG(&(uart->huart), UART_FLAG_TC);
    uart->huart.Instance->DR = c;
    while (__HAL_UART_GET_FLAG(&(uart->huart), UART_FLAG_TC) == RESET);
    return 1;
}
static int stm32_getc(struct rt_serial_device *serial)
{
    int ch;
    struct stm32_uart *uart;
    RT_ASSERT(serial != RT_NULL);
    uart = (struct stm32_uart *)serial->parent.user_data;
    ch = -1;
    if (__HAL_UART_GET_FLAG(&uart->huart, UART_FLAG_RXNE) != RESET)
    {
        ch = uart->huart.Instance->DR & 0xff;
    }
    return ch;
}
static void uart_isr(struct rt_serial_device *serial)
{
    struct stm32_uart *uart = (struct stm32_uart *) serial->parent.user_data;
    RT_ASSERT(uart != RT_NULL);
    if ((__HAL_UART_GET_FLAG(&uart->huart, UART_FLAG_RXNE) != RESET) && (__HAL_UART_GET_IT_SOURCE(&uart->huart, UART_IT_RXNE) != RESET))
    {
        rt_hw_serial_isr(serial, RT_SERIAL_EVENT_RX_IND);
        __HAL_UART_CLEAR_FLAG(&uart->huart, UART_FLAG_RXNE);
    }
}
static const struct rt_uart_ops stm32_uart_ops =
{
    stm32_configure,
    stm32_control,
    stm32_putc,
    stm32_getc,
};
/* UART1 device driver structure */
struct stm32_uart uart1 =
{
    {USART1},
    USART1_IRQn
};
struct rt_serial_device serial1;

void USART1_IRQHandler(void)
{
    /* enter interrupt */
    rt_interrupt_enter();
    uart_isr(&serial1);
    /* leave interrupt */
    rt_interrupt_leave();
}
int rt_hw_usart_init(void)
{
	struct stm32_uart *uart;
	struct serial_configure config = RT_SERIAL_CONFIG_DEFAULT;

	uart = &uart1;
	config.baud_rate = BAUD_RATE_115200;
	serial1.ops    = &stm32_uart_ops;
	serial1.config = config;
	/* register UART1 device */
	rt_hw_serial_register(&serial1, "uart1",
						  RT_DEVICE_FLAG_RDWR | RT_DEVICE_FLAG_INT_RX,
						  uart);

	return 0;
}
INIT_BOARD_EXPORT(rt_hw_usart_init);




