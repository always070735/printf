//#define _DEBUG
//#define _DEBUG_DETAIL

//UART
#ifdef _DEBUG 
    
    #include <stdio.h>
    int _write(int file,char *ptr,int len)
    {
        int i;
        for(i=0;i<len;i++)
        {
            UART_UartPutChar(*ptr++);
        }
        return(len);
    }
    asm(".global _printf_float");
    
    #ifdef _DEBUG_DETAIL
        #define dbg_printf(x, args...) printf("%s,%s,%d:" x, __FILE__, __FUNCTION__, __LINE__, ##args)
    #else
        #define dbg_printf(x, args...) my_printf("%s" x, "", ##args)
    #endif
#else
    #define dbg_printf(x, args...)
#endif