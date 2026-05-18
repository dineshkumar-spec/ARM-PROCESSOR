#include <stdint.h>

//clock enable
#define RCC_AHB1ENR (*(volatile uint32_t*)0x40023830)
#define RCC_APB2ENR (*(volatile uint32_t*)0x40023844)

//mode
#define GPIOC_MODER (*(volatile uint32_t*)0x40020800)
#define GPIOA_AFRL  (*(volatile uint32_t*)0x40020020)

//__usart__
#define USART6_SR   (*(volatile uint32_t*)0x40011400)
#define USART6_DR   (*(volatile uint32_t*)0x40011004)
#define USART6_BRR  (*(volatile uint32_t*)0x40011008)
#define USART6_CR1  (*(volatile uint32_t*)0x4001100c)

void GPIO_Init(){
	// Enable GPIOC clock
	RCC_AHB1ENR |= (1<<2);

	// Configure PC6 (TX) and PC7 (RX) as Alternate Function
	// PC6: bits[13:12], PC7: bits[15:14]
	GPIOC_MODER &= ~(3<<12);  // Clear PC6
	GPIOC_MODER &= ~(3<<14);  // Clear PC7
	GPIOC_MODER |= (2<<12);   // Set PC6 to AF (6)
	GPIOC_MODER |= (2<<14);   // Set PC7 to AF (7)

	// Set Alternate Function to USART6 (AF8)
	// AFRL[27:24] for PC6, AFRL[31:28] for PC7
	GPIOA_AFRL &= ~(15<<24);   // Clear PC6 AF bits
	GPIOA_AFRL &= ~(15<<28);   // Clear PC7 AF bits
	GPIOA_AFRL |= (8<<24);     // Set PC6 to AF8
	GPIOA_AFRL |= (8<<28);     // Set PC7 to AF8
}

void USART_Init(){
	// Enable USART6 clock on APB2
	RCC_APB2ENR |= (1<<5);

	// Set Baud Rate = 9600
	// For STM32F411 with APB2 clock = 16MHz
	// BRR = fck / (16 * Baud) = 16,000,000 / (16 * 9600) = 104.16667=0X683

	USART6_BRR = 0x683;

	// Enable TX
	USART6_CR1 |= (1<<3);

	// Enable RX
	USART6_CR1 |= (1<<2);

	// Enable USART6
	USART6_CR1 |= (1<<13);
}

void USART6_SendChar(char ch)
{
	// Wait until TX buffer is empty (TXE flag)
	while(!(USART6_SR & (1<<7)));

	// Send character
	USART6_DR = ch;
}

void USART6_SendString(char *str)
{
	while(*str)
	{
		USART6_SendChar(*str++);
	}
}

char USART6_ReceiveChar(void)
{
	while(!(USART6_SR & (1<<5))){}
    return USART6_DR;
}
int main(void)
{
	char data;
	GPIO_Init();
	USART_Init();

	// Add small delay to ensure USART is ready
	//delay_ms(100);
	USART6_SendString("Embedded System\n");
	while(1){
		data = USART6_ReceiveChar();
		USART6_SendChar(data);
		//delay_ms(100);  // Send every 1 second
	}

	return 0;
}
