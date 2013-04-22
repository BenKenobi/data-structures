#include <ArrayList.h>
#include <debug.h>

//TODO Tests
//TODO warning for returning NULL as T
//TODO resize() may allocate too big a size and fail
//TODO resize() may have a memory leak, we shouldn't crash at 33768 elements
//TODO do 1 resize, read all elements to check they're all right

namespace it {

namespace ds {

namespace list {

ArrayList::ArrayList() {
    DEBUG("%s: class constructor\n", __func__);
    len = 10;
    nElem = 0;
    a = new int[len];
}

ArrayList::~ArrayList() {
    DEBUG("%s: class destructor\n", __func__);
    delete[] a;
}

int ArrayList::size() {
    return nElem;
}

T ArrayList::get(int i) {
    DEBUG("%s: Getting Element %d %d\n", __func__, i, a[i]);
    if (i >= 0 && i < nElem)
        return a[i];
    else
        return NULL;
}

T ArrayList::set(int i, T x) {
    DEBUG("%s: Setting Element %d in place of Element %d @ %d\n", __func__, x, a[i], i);
    T oldOne = NULL;
    if (i >= 0 && i < nElem) {
        oldOne = a[i];
        a[i] = x;
    }
    return oldOne;
}

void ArrayList::add(int i, T x) {
    DEBUG("%s: Adding Element %d in place of Element %d @ %d\n", __func__, x, a[i], i);
    // check dimensions
    if (i < 0 && i > nElem)
        return;
    // resize iff it is FULL
    if (nElem == (len - 1))
        resize(len * 2);
    // shift right
    displaceRight(i);
    // set new element
    a[i] = x;
    // increment
    nElem += 1;
}

T ArrayList::remove(int i) {
    DEBUG("%s: Removing Element %d from %d \n", __func__, a[i], i);
    T remElem = NULL;
    // check dimensions
    if (i < 0 && i > nElem)
        return NULL;
    // remove element
    remElem = a[i];
    // shift left
    displaceLeft(i);
    // decrement
    nElem -= 1;
    // define the bound
    if(nElem < (len / 4))
        resize(len / 2);
    return remElem;
}

void ArrayList::resize(int newDim) {
    DEBUG("%s: Resize to %d from %d \n", __func__, newDim, nElem);
    T *newArr = new T[newDim];
    for (int i = 0; i < nElem; i++)
        newArr[i] = a[i];
    delete[] a;
    a = newArr;
}

inline void ArrayList::displaceRight(int idx) {
    DEBUG("%s: Displace Right from %d \n", __func__, idx);
    for (int i = nElem; i > idx; i--)
        a[i] = a[i - 1];
}

inline void ArrayList::displaceLeft(int idx) {
    DEBUG("%s: Displace Left from %d \n", __func__, idx);
    for (int i = idx; i < nElem - 1; i++)
        a[i] = a[i + 1];
}

} /* list */

} /* ds */

} /* it */
