#ifndef MEM_ARRAY_MEM_ARRAY_TCC_
#define MEM_ARRAY_MEM_ARRAY_TCC_

/*!
 * Generic array interface.
 */
template <class T>
class MemArray {
  public:
    MemArray(void) {}
    MemArray(T (*)(size_t), void (*)(size_t, T), size_t, size_t, size_t*);
    T operator=(T);
    operator T(void);
    MemArray<T> operator[](size_t);
    size_t offsetAt(size_t);
  private:
    T (*_read)(size_t);
    void (*_write)(size_t, T);
    size_t _elementSize;
    size_t _offset;
    size_t _dim;
    size_t* _shape;
};


/*!
 * Create an array at location `offset`.
 *
 * \param read Read function.
 * \param write Write function.
 * \param offset Array location.
 * \param dim Array dimensions.
 * \param shape Array shape.
 */
template <class T>
MemArray<T>::MemArray(
    T (*read)(size_t), void (*write)(size_t, T),
    size_t offset, size_t dim, size_t* shape) {
  _read = read;
  _write = write;
  _offset = offset;
  _dim = dim;
  _shape = shape;

  _elementSize = sizeof(T);
  if (_dim) {
    for (size_t i = 0; i < _dim - 1; i++) {
      _elementSize *= _shape[i];
    }
  }
}

/*!
 * Get the location of array element `index`.
 *
 * \param index Element index.
 *
 * \return Location of array element `index`.
 */
template <class T>
size_t MemArray<T>::offsetAt(size_t index) {
  return index * _elementSize + _offset;
}

/*!
 * Assign a value to an element.
 *
 * \param data Value.
 *
 * \return Assigned value.
 */
template <class T>
T MemArray<T>::operator=(T data) {
  _write(_offset, data);

  return data;
}

/*!
 * Retrieve an element.
 *
 * \return Value of array element `_index`.
 */
template <class T>
MemArray<T>::operator T(void) {
  return _read(_offset);
}

/*!
 * Access an element.
 *
 * \return Array for array element `index`.
 */
template <class T>
MemArray<T> MemArray<T>::operator[](size_t index) {
  return MemArray<T>(_read, _write, offsetAt(index), _dim - 1, &_shape[1]);
}

#endif
