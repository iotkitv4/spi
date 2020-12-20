/** Beispiel fuer die Dot LED Matrix Ansteuerung
*/
#include "mbed.h"
#include "Driver.h"

// Dot LED Matrix Driver (SPI-2 Anschluss)
LMDriver matrix( MBED_CONF_IOTKIT_DOTLED_MOSI, MBED_CONF_IOTKIT_DOTLED_MISO, MBED_CONF_IOTKIT_DOTLED_SCLK, MBED_CONF_IOTKIT_DOTLED_SS );

int main()
{
    matrix.Setup();
    // Scrollgeschwindigkeit
    matrix.SetWaitTime( 400 );

    while   ( 1 )
    {
        // String welcher scrollend dargestellt wird.
        printf( "Ein Text welche auf dem Display erscheint\r\n" );
        matrix.DisplayString( "Das ist ein Test mit 26.3C" );
        thread_sleep_for( 1000 );
        
        // Alfabet anzeigen
        for ( unsigned char i = '0'; i <= 'z'; i++ )
        {
            matrix.DisplayChar( i );
            thread_sleep_for( 500 );
        }
    }
}
