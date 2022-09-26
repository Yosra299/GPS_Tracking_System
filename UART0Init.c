void UART0Init(){
	SYSCTL_RCGCUART_R |= 0x01 ;// provide clock to UART0 
	SYSCTL_RCGCGPIO_R |= 0x01; // Enable clock for PORTF
	UART0_CTL_R &=~UART_CTL_UARTEN; // disable UART0 
	UART0_IBRD_R =104; // 16MHz/16=1MHz, 1MHz/104=9600 baud rate 
	UART0_FBRD_R =11; // fraction part
	UART0_CC_R = UART_CC_CS_SYSCLK; // use system clock (default)
	UART0_LCRH_R =(UART_LCRH_FEN | UART_LCRH_WLEN_8 ); // UART Enable FIFOs and  8 bits
	UART0_CTL_R |=(UART_CTL_UARTEN | UART_CTL_RXE| UART_CTL_TXE);// UART Enable , UART Transmit Enable , UART Receive Enable
	GPIO_PORTA_AFSEL_R |= 0x03; // Enable serial 
	GPIO_PORTA_PCTL_R =( GPIO_PORTA_PCTL_R &~ 0xFF)| 0x00000011; //  Enable to U0RX on PA0,U0TX on PA1
  GPIO_PORTA_DEN_R |= 0x03;		
} 
