#ifndef MEM_ARRAY_PROGMEM_HELPER_TCC_
#define MEM_ARRAY_PROGMEM_HELPER_TCC_

#include <avr/pgmspace.h>


/*!
 * Read a value of type `T` from PROGMEM.
 *
 * \param offset Location.
 *
 * \return Value at `offset`.
 */
template <class T>
T PROGMEMRead(size_t offset) {
  T data;

  for (uint8_t i = 0; i < sizeof(T); i++) {
    ((uint8_t*)&data)[i] = pgm_read_byte(offset + i);
  }

  return data;
}

/*!
 * Writing to PROGMEM is not possible.
 */
template <class T>
void PROGMEMWrite(size_t, T) {}

#endif
