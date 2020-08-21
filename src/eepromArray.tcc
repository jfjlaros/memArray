#ifndef MEM_ARRAY_EEPROM_ARRAY_TCC_
#define MEM_ARRAY_EEPROM_ARRAY_TCC_

#include "memArray.tcc"
#include "eepromHelper.tcc"

/*!
 * Generic array interface to EEPROM.
 */
template <class T>
class EEPROMArray : public MemArray<T> {
  public:
    EEPROMArray(void) {}
    EEPROMArray(size_t, size_t=1, size_t* _=NULL);
};


/*!
 * Create an array at location `offset`.
 *
 * \param offset Array location.
 * \param dim Array dimensions.
 * \param shape Array shape.
 */
template <class T>
EEPROMArray<T>::EEPROMArray(size_t offset, size_t dim, size_t* shape)
    : MemArray<T>(EEPROMRead, EEPROMWrite, offset, dim, shape) {}

#endif
