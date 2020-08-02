#ifndef EEPROM_PROXY_TCC_
#define EEPROM_PROXY_TCC_

#include "eepromHelper.tcc"

/*!
 * Proxy for assignment and retrieval.
 */
template <class T>
class EEPROMProxy {
  public:
    EEPROMProxy(void) {}
    EEPROMProxy(size_t);
    T operator=(T);
    operator T(void);
  private:
    size_t _offset;
};


/*!
 * Create a Proxy.
 *
 * \param offset Array location.
 * \param index Element index.
 */
template <class T>
EEPROMProxy<T>::EEPROMProxy(size_t offset) {
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
T EEPROMProxy<T>::operator=(T data) {
  EEPROMWrite(_offset, data);

  return data;
}

/*!
 * Retrieve an element.
 *
 * \return Value of array element `_index`.
 */
template <class T>
EEPROMProxy<T>::operator T(void) {
  return EEPROMRead<T>(_offset);
}

#endif
