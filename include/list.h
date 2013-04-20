#ifndef LIST_H_
#define LIST_H_

#include "types.h"

namespace it {

namespace ds {

namespace list {

class List {
    public:
        virtual int size() = 0;
        virtual T get(int i) = 0;
        virtual T set(int i, T x) = 0;
        virtual void add(int i, T x) = 0;
        virtual T remove(int i) = 0;
};

} /* list */

} /* ds */

} /* it */

#endif /* LIST_H_ */
