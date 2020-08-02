#ifndef MEM_ARRAY_EEPROM_ARRAY_TCC_
#define MEM_ARRAY_EEPROM_ARRAY_TCC_

#include "eepromProxy.tcc"

/*!
 * Generic array interface to EEPROM.
 */
template <class T>
class EEPROMArray {
  public:
    EEPROMArray(void) {}
    EEPROMArray(size_t);
    EEPROMProxy<T> operator[](size_t);
    size_t offsetAt(size_t);
  private:
    size_t _offset;
};


/*!
 * Create an array at location `offset`.
 *
 * \param offset Array location.
 */
template <class T>
EEPROMArray<T>::EEPROMArray(size_t offset) {
  _offset = offset;
}

/*!
 * Get the location of array element `index`.
 *
 * \param index Element index.
 *
 * \return Location of array element `index`.
 */
template <class T>
size_t EEPROMArray<T>::offsetAt(size_t index) {
  return _offset + sizeof(T) * index;
}

/*!
 * Access an element.
 *
 * \return Proxy for array element `index`.
 */
template <class T>
EEPROMProxy<T> EEPROMArray<T>::operator[](size_t index) {
  return EEPROMProxy<T>(offsetAt(index));
}

#endif
