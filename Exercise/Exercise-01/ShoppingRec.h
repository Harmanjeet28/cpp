//Harmanjeet Singh Hara
//Student ID#:118624220 , email: hhara@myseneca.ca


#ifndef NAMESPACE_SHOPPINGREC_H 
#define NAMESPACE_SHOPPINGREC_H

namespace sdds {

    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;

    struct ShoppingRec {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };


    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);

}

#endif

