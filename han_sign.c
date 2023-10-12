#include "main.h"

/**
 * sign_call - Functions that helps handle the crtl + c in shell terminal
 * @cut: __attribute__((unused)) Buffer holding and pass the sign call.
 */

void sign_call(int __attribute__((unused)) cut)
{
	write(1, "\n^-^ ", 5);
}
