#ifndef MEM_ARRAY_EEPROM_HELPER_TCC_
#define MEM_ARRAY_EEPROM_HELPER_TCC_

#include <EEPROM.h>


/*!
 * Read a value of type `T` from EEPROM.
 *
 * \param offset Location.
 *
 * \return Value at `offset`.
 */
template <class T>
T EEPROMRead(size_t offset) {
  T data;

  for (uint8_t i = 0; i < sizeof(T); i++) {
    ((uint8_t*)&data)[i] = EEPROM.read(offset + i);
  }

  return data;
}

/*!
 * Write a value of type `T` to EEPROM.
 *
 * \param offset Location.
 * \param data Value.
 */
template <class T>
void EEPROMWrite(size_t offset, T data) {
  for (uint8_t i = 0; i < sizeof(T); i++) {
    EEPROM.write(offset + i, ((uint8_t*)&data)[i]);
  }
}

#endif
