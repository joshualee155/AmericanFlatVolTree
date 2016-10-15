//
//  clsAmericanFlatVolTree.h
//  AmericanFlatVolTree
//
//  Created by Xiangyu Joshua Li on 12/09/2015.
//  Copyright (c) 2015 Xiangyu Joshua Li. All rights reserved.
//

#ifndef AmericanFlatVolTree_clsAmericanFlatVolTree_h
#define AmericanFlatVolTree_clsAmericanFlatVolTree_h

#include <vector>
using std::vector;

class clsAmericanFlatVolTree
{
public:
    clsAmericanFlatVolTree(double S,
                           double K,
                           double T,
                           double sig,
                           double r,
                           double div = 0.0,
                           bool IsCall = true,
                           int N = 120);
    ~clsAmericanFlatVolTree();
    double get_price();
    
private:
    void init(int N);
    double S0, K, T, sig, r, div;
    int N;
    bool isCall;
    double pu,pd,pm;
    double u,d,dt;
    vector< vector<double> > S;
    vector< vector<double> > C;
    
};


#endif
