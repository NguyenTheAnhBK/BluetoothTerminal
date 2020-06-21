#include<avr/io.h>
#include<avr/interrupt.h>

#define F_CPU 8000000UL // 8MHz
#include<util/delay.h>

#include "KSC_UART.h"

volatile unsigned char _data;


int main(){
	// Baud rate = 57600 bps (f = 8MHz) -> UBRRL = 8
	USART_Init(8);
	
	sei(); // set bit I cho phep ngat toan cuc
	while(1){
		//for(char i = 32; i < 128; i++){
		//	USART_Transmit(i);
		//	_delay_ms(100);
		//}

		//USART_Transmit(USART_Receive);
		//_delay_ms(100);
		USART_Receive();
		_delay_ms(100);
	}
			
	return 0;
}

// Trinh phuc vu ngat USART hoan tat nhan
ISR(SIG_UART_RECV){
	_data = UDR;
	USART_Transmit(_data);
}
