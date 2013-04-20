#ifndef ARRAY_LIST_H_
#define ARRAY_LIST_H_

#include "list.h"

namespace it {

namespace ds {

namespace list {

class ArrayList : public List {
    private:
        T *a;       /*  */
        int len;    /*  */
        int nElem; /*  */
        /**
        *
        */
        void resize(int newDim);
        /**
        *
        */
        void displaceRight(int idx);
        /**
        *
        */
        void displaceLeft(int idx);

    public:
        ArrayList();
        ~ArrayList();
        int size();
        T get(int i);
        T set(int i, T x);
        void add(int i, T x);
        T remove(int i);
};

} /* list */

} /* ds */

} /* it */

#endif /* ARRAY_LIST_H_ */
