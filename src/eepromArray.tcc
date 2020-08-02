#ifndef EEPROM_ARRAY_TCC_
#define EEPROM_ARRAY_TCC_

#include <EEPROM.h>

/*!
 * Generic array interface to EEPROM.
 */
template <class T>
class EEPROMArray {
  /*!
   * Proxy for assignment and retrieval.
   */
  class Proxy {
    public:
      Proxy(void) {}
      Proxy(size_t);
      T operator=(T);
      operator T(void);
    private:
      size_t _offset;
  };
  public:
    EEPROMArray(void) {}
    EEPROMArray(size_t);
    Proxy operator[](size_t);
    size_t offsetAt(size_t);
  private:
    size_t _offset;
};


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


/*!
 * Create a Proxy.
 *
 * \param offset Array location.
 * \param index Element index.
 */
template <class T>
EEPROMArray<T>::Proxy::Proxy(size_t offset) {
  _offset = offset;
}

/*!
 * Assign a value to an array element.
 *
 * \param data Value.
 *
 * \return Assigned value.
 */
template <class T>
T EEPROMArray<T>::Proxy::operator=(T data) {
  EEPROMWrite(_offset, data);

  return data;
}

/*!
 * Retrieve an element.
 *
 * \return Value of array element `_index`.
 */
template <class T>
EEPROMArray<T>::Proxy::operator T(void) {
  return EEPROMRead<T>(_offset);
}


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
typename EEPROMArray<T>::Proxy EEPROMArray<T>::operator[](size_t index) {
  return Proxy(offsetAt(index));
}

#endif
