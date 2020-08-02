#ifndef MEM_ARRAY_PROGMEM_ARRAY_TCC_
#define MEM_ARRAY_PROGMEM_ARRAY_TCC_

#include "progmemHelper.tcc"

/*!
 * Generic array interface to PROGMEM.
 */
template <class T>
class PROGMEMArray {
  public:
    PROGMEMArray(void) {}
    PROGMEMArray(T const*);
    T operator[](size_t);
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
PROGMEMArray<T>::PROGMEMArray(T const* offset) {
  _offset = (size_t)offset;
}

/*!
 * Get the location of array element `index`.
 *
 * \param index Element index.
 *
 * \return Location of array element `index`.
 */
template <class T>
size_t PROGMEMArray<T>::offsetAt(size_t index) {
  return _offset + sizeof(T) * index;
}

/*!
 * Access an element.
 *
 * \return Value of array element `index`.
 */
template <class T>
T PROGMEMArray<T>::operator[](size_t index) {
  return PROGMEMRead<T>(_offset + sizeof(T) * index);
}

#endif
