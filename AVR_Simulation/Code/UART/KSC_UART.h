
// Initial
void USART_Init(unsigned int baud){
	// Set baud rate with USART Baud Rate Register
	// Voi U2X = 0
	UBRRH = (unsigned char) (baud >> 8);
	UBRRL = (unsigned char) baud;
	
	// Enable receiver and transmitter (USART Control and Status Register B)
	UCSRB = (1 << RXEN) | (1 << TXEN);
	// Cho phep ngat sau khi nhan xong
	UCSRB |= (1 << RXCIE);

	// Set frame format: 8 (data), no parity (USART Parity Mode = 0), 1 stop (USBS = 0)
	// Chon thanh ghi USCRC voi USART Register Select 
	// Chon charecter size voi USART Character Size (UCSZ0 -> UCSZ2)
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

// Transmitter
void USART_Transmit(unsigned char c){
	// UART Data Register Empty = 1 thi bat dau truyen (nhan) du lieu
	while(!(UCSRA & (1 << UDRE))){}; 
	UDR = c; // UART Data Register
}

// Receiver
unsigned char USART_Receive(){
	while(!(UCSRA & (1 << RXC))){};
	// Get and return received data from buffer
	return UDR;
}



