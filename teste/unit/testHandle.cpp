#include"testHandle.hpp"
#include"assert.h"
int numHandleCreated=0;
int numHandleDeleted=0;
int numBodyCreated=0;
int numBodyDeleted=0;
void testHandle(){
    int nhant = numHandleCreated;
	int nbant = numBodyCreated;
	int nhDeleted = numHandleDeleted;
	int nbDeleted = numBodyDeleted;
    StockHandle *x = new StockHandle(0, "x");
    StockHandle *x1 = new StockHandle(0, "x1");
    assert(numHandleCreated == nhant + 2);
    {
        StockHandle *x2 = new StockHandle(0, "x2"); 
        StockHandle *x3 = new StockHandle(0, "x3");
        assert(numHandleCreated == nhant + 4);
        x2->deleleStockHandle();
        assert(numHandleDeleted == nhDeleted + 1);

    }
    cout << "Handle its working ";

}
    