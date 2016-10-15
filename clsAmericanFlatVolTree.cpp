//
//  clsAmericanFlatVolTree.cpp
//  AmericanFlatVolTree
//
//  Created by Xiangyu Joshua Li on 12/09/2015.
//  Copyright (c) 2015 Xiangyu Joshua Li. All rights reserved.
//

#include "clsAmericanFlatVolTree.h"
#include <cmath>

double max(double a, double b);


clsAmericanFlatVolTree::clsAmericanFlatVolTree(double _S0,
                                               double _K,
                                               double _T,
                                               double _sig,
                                               double _r,
                                               double _d,
                                               bool _isCall,
                                               int _N)
:S0(_S0), K(_K), T(_T), sig(_sig), r(_r), div(_d), isCall(_isCall), N(_N)
{
    init(N);
}

clsAmericanFlatVolTree::~clsAmericanFlatVolTree(){}

void clsAmericanFlatVolTree::init(int _N)
{
    dt = T/N;
    double sqdt = sqrt(2*dt);
    double yield = r - div;
    u = exp(sig*sqdt);
    d = 1.0/u;

    pu = pow( (exp(yield*dt/2.0) - exp(-sig*sqdt/2.0))/(exp(sig*sqdt/2.0) - exp(-sig*sqdt/2.0)) , 2.0);
    pd = pow( (exp(sig*sqdt/2.0) - exp(yield*dt/2.0))/(exp(sig*sqdt/2.0) - exp(-sig*sqdt/2.0)) , 2.0);
    pm = 1.0 - pu - pd;
    
    S.resize(_N + 1);
    for (int i = 0; i <= _N; ++i)
    {
        S[i].resize(2*i+1);
        if (i == 0)
        {
            S[i][0] = S0;
        }
        else
        {
            for (int j = 0; j < (2*i-1); ++j)
            {
                S[i][j] = S[i-1][j]*u;
            }
            S[i][2*i-1] = S[i-1][2*i-2];
            S[i][2*i] = S[i-1][2*i-2]*d;
        }
    }
    C.resize(_N + 1);
    for (int i = _N; i >= 0; --i)
    {
        C[i].resize(2*i+1);
        if (i == _N)
        {
            for ( int j = 0; j < (2*i+1); ++j)
            {
                C[i][j] = isCall ? max(S[i][j]-K, 0.0) : max(K-S[i][j], 0.0);
            }
        }
        else
        {
            for ( int j = 0; j < (2*i+1); ++j)
            {
                C[i][j] = max( exp(-r*dt)*(pu*C[i+1][j] + pm*C[i+1][j+1] + pd*C[i+1][j+2]), isCall ? max(S[i][j]-K, 0.0) : max(K-S[i][j], 0.0) );
            }
        
        }
    }
    
    
}

double clsAmericanFlatVolTree::get_price()
{
    return C[0][0];
}

double max(double a, double b)
{
    return a > b? a : b;
}

