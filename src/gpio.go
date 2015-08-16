package src

/*

#include "gpio.h"

extern int analogReadBank(int bank);

*/
import "C"
import (
	"errors"
)

func AnalogRead(bank int) (value int, err error) {
	value = int(C.analogReadBank(C.int(bank)))
	if value == -1 {
		err = errors.New("Error reading ADC from /dev/mem")
	}
	return
}
