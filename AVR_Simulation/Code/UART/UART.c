#include<avr/io.h>
#include<avr/interrupt.h>

#define F_CPU 8000000UL // 8MHz
#include<util/delay.h>

#include "KSC_UART.h"


int main(){
	// Baud rate = 57600 bps (f = 8MHz) -> UBRRL = 8
	USART_Init(8);

	USART_Transmit_String("Hello World\r\n");

	while(1){
		//for(char i = 32; i < 128; i++){
		//	USART_Transmit(i);
		//	_delay_ms(100);
		//}

		//USART_Transmit(USART_Receive);
		//_delay_ms(100);
		unsigned char data = USART_Receive();
		//_delay_ms(10);
		USART_Transmit(data);
		USART_Transmit('\r');
		USART_Transmit('\n');
		_delay_ms(10);
	}
			
	return 0;
}


