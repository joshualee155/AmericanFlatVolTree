//
//  main.cpp
//  AmericanFlatVolTree
//
//  Created by Xiangyu Joshua Li on 12/09/2015.
//  Copyright (c) 2015 Xiangyu Joshua Li. All rights reserved.
//

#include <iostream>
#include "clsAmericanFlatVolTree.h"

using namespace std;

int main(int argc, const char * argv[]) {
    

    clsAmericanFlatVolTree tree(100, 100, 0.5, 0.2, 0.01, 0.005, true, 4096);
    
    cout << tree.get_price() << endl;
    
    return 0;
}
