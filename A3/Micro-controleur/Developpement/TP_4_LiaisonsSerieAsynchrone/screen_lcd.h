

// INIT FUNCTION 
void init_screen_lcd(void);

// FUNCTION 
void acq(void);
void set_ddram(unsigned char addr); 
void screen_action(unsigned char keyboard);
void screen_word_write(char *word); 
void screen_number_write(int number);
//void writeLCD_mem(char c, int adresse);