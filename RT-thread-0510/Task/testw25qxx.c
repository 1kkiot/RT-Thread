#include "testw25qxx.h"
#include "w25qxx.h"
#include "TW25QXX.h"
uint8_t wData[0x100];
uint8_t rData[0x100];
uint32_t i;
uint8_t ID[2];

//void spi_flash_test()
//{
//	W25qxx_Init();
//	//W25qxx_EraseChip();
//	W25qxx_EraseSector(0x0);
//	for(i=0;i<0x100-2;i++)
//	{
//		wData[i] = 'b';
//		rData[i] = 0;
//	}
//	W25qxx_WriteByte(wData[1],0x0);
//	W25qxx_ReadByte(&rData[2],0x0);
//	printf("w=0x%02x,r=0x%02x\r\n",wData[1],rData[2]);
//	W25qxx_EraseSector(0x0);
//	W25qxx_WritePage(wData,0,0,100);
//	W25qxx_ReadPage(&rData[0],0,0,100);
//	printf("r=%s\r\n",rData);
//}


void spi_flash_test()
{
	uint8_t temp,j;
	printf("\r\n SPI-W25Qxxx Example \r\n\r\n");

	/*##-1- Read the device ID  ########################*/ 
	BSP_W25Qx_Init();
	BSP_W25Qx_Read_ID(ID);
	printf(" W25Qxxx ID is : 0x%02X 0x%02X \r\n\r\n",ID[0],ID[1]);
	for(j=0;j<120;j++)
	{
		temp = BSP_W25Qx_Erase_Block(j);

		if(temp == W25Qx_OK)
		{
			printf(" SPI Erase %d Block ok\r\n",j);
		}
		else
		{
			printf("error11111\r\n");//Error_Handler();
		}

		for(i =0;i<0x100;i ++)
		{
			wData[i] = i;
			rData[i] = 0;
		}

		if(BSP_W25Qx_Write(wData,j,0x100)== W25Qx_OK)
		{
			printf(" SPI Write %d Block ok\r\n",j);
		}
		else
		{
			printf("error222222\r\n");//Error_Handler();
		}

		if(BSP_W25Qx_Read(rData,j,0x100)== W25Qx_OK)
		{
			printf(" SPI Read %d Block ok\r\n\r\n",j);
		}
		else
		{
			printf("error333333\r\n");//Error_Handler();
		}

//		printf("SPI Read Data : \r\n");
//		for(i =0;i<0x100;i++)
//		{
//			printf("0x%02X  ",rData[i]);
//		}
//		printf("\r\n\r\n");

		if(memcmp(wData,rData,0x100) == 0 )
		{
			printf(" W25QxxFV SPI Test OK\r\n");
		}
		else
		{
			printf(" W25QxxFV SPI Test False\r\n");
		}
	}


}

















