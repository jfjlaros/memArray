#ifndef MEM_ARRAY_PROGMEM_ARRAY_TCC_
#define MEM_ARRAY_PROGMEM_ARRAY_TCC_

#include "memArray.tcc"
#include "progmemHelper.tcc"

/*!
 * Generic array interface to PROGMEM.
 */
template <class T>
class PROGMEMArray : public MemArray<T> {
  public:
    PROGMEMArray(void) {}
    PROGMEMArray(T const*, size_t=1, size_t* _=NULL);
};


/*!
 * Create an array at location `offset`.
 *
 * \param offset Array location.
 * \param dim Array dimensions.
 * \param shape Array shape.
 */
template <class T>
PROGMEMArray<T>::PROGMEMArray(T const* offset, size_t dim, size_t* shape)
    : MemArray<T>(PROGMEMRead, PROGMEMWrite, (size_t)offset, dim, shape) {}

#endif
