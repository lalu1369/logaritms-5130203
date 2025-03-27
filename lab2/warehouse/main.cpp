#include "Product.h"
#include "Warehouse.h"
#include <string>

using namespace std;

int main()
{
    Warehouse warehouseCenter = Warehouse(101, CategoryEnum::Center, 100, 100, 100);
    Warehouse warehouseWest   = Warehouse(102, CategoryEnum::West,    50,  60, 100);
    Warehouse warehouseEast   = Warehouse(103, CategoryEnum::East,    60, 120, 100);

    bool isExited = false;
    int opt;
    while (!isExited)
    {
        cout << "----------OPTIONS------------"   << endl;
        cout << "1) Insert Product"               << endl;
        cout << "2) List Products in Warehouse"   << endl;
        cout << "3) Search Productby description" << endl;
        cout << "4) Delete products"              << endl;
        cout << "Exit Program"                    << endl;
        cout << "----------------------"          << endl;

        cout << "Introduce Option: ";
        cin  >> opt;

        // 1
        string  description;
        float   price;
        int     quantity;
        double  lpLat;
        double  lpLong;
        Product newProduct;

        float distanceW1;
        float distanceW2;
        float distanceW3;

        // 2
        int numberWh;

        // 3
        string description2;
        bool isFounded = false;
        Product searchedProduct = Product();

        //4
        string barcodeDP;
        bool isProductDeleted = false;

        switch (opt)
        {
        case 1:
            cout << "----------INSERT PRODUCT------------" << endl;
            cout << " Insert Description: "                << endl;
            cin  >> description;
            cout << " Insert price: "                      << endl;
            cin  >> price;
            cout << " Insert Quantity"                     << endl;
            cin  >> quantity;
            cout << " Insert Lat"                          << endl;
            cin  >> lpLat;
            cout << " Insert Long"                         << endl;
            cin  >> lpLong;

            try{
                newProduct = Product(406, description, price, quantity, lpLat, lpLong);

                distanceW1 = warehouseCenter.getDistanceBetweenPT(newProduct);
                distanceW2 = warehouseEast.getDistanceBetweenPT(newProduct);
                distanceW3 = warehouseWest.getDistanceBetweenPT(newProduct);
    
                if (distanceW1 <= distanceW2 && distanceW1 <= distanceW3)
                {
                    warehouseCenter.addProduct(newProduct);
                }
                else if (distanceW2 <= distanceW1 && distanceW2 <= distanceW3)
                {
                    warehouseEast.addProduct(newProduct);
                }
                else
                {
                    warehouseWest.addProduct(newProduct);
                }
    
                cout << "Product Added Succesfully" << endl;
                cout << "----------------------"    << endl;

            }catch(const std::exception& e){
                cerr << "Error: " << e.what() << endl;
            }

            break;

        case 2:
            cout << "----------SELECT WAREHOUSE------------" << endl;
            cout << " 1) Center \n 2) West \n 3) East "      << endl;
            cout << " Select: "                              << endl;
            cin  >> numberWh;
            switch (numberWh)
            {
            case 1:
                for (int i = 0; i < warehouseCenter.getSizeListOfProducts(); i++)
                {
                    cout << warehouseCenter.getListOfProducts()[i].toString();
                }
                break;
            case 2:
                for (int i = 0; i < warehouseWest.getSizeListOfProducts(); i++)
                {
                    cout << warehouseWest.getListOfProducts()[i].toString();
                }
                break;
            case 3:
                for (int i = 0; i < warehouseEast.getSizeListOfProducts(); i++)
                {
                    cout << warehouseEast.getListOfProducts()[i].toString();
                }
                break;
            default:
                cout << "Invalid Option" << endl;
                break;
            }
            cout << "----------------------" << endl;

            break;

        case 3:

            cout << "----------SEARCH PRODUCT BY DESCRIPTION------------" << endl;
            cout << " Insert Description: " << endl;
            cin >> description2;

            isFounded = warehouseCenter.searchProduct(description2, searchedProduct);
            if (!isFounded)
            {
                isFounded = warehouseEast.searchProduct(description2, searchedProduct);
            }
            if (!isFounded)
            {
                isFounded = warehouseWest.searchProduct(description2, searchedProduct);
            }

            if (isFounded)
            {
                cout << searchedProduct.toString();
            }
            else
            {
                cout << "Product NOT FOUNDED..." << endl;
            }

            cout << "----------------------" << endl;
            break;

        case 4:

            cout << "----------DELETE PRODUCT BY BARCODE------------" << endl;
            cout << " Insert Barcode: " << endl;
            cin >> barcodeDP;

            for (int i = 0; i < warehouseCenter.getSizeListOfProducts(); i++)
            {
                if (warehouseCenter.getListOfProducts()[i].getBarCode().compare(barcodeDP) == 0){
                    warehouseCenter.deleteProduct(warehouseCenter.getListOfProducts()[i]);
                    isProductDeleted = true;
                }
            }


            for (int i = 0; i < warehouseEast.getSizeListOfProducts(); i++)
            {
                if (warehouseEast.getListOfProducts()[i].getBarCode().compare(barcodeDP) == 0){
                    warehouseEast.deleteProduct(warehouseEast.getListOfProducts()[i]);
                    isProductDeleted = true;
                }
            }

            for (int i = 0; i < warehouseWest.getSizeListOfProducts(); i++)
            {
                if (warehouseWest.getListOfProducts()[i].getBarCode().compare(barcodeDP) == 0){
                    warehouseWest.deleteProduct(warehouseWest.getListOfProducts()[i]);
                    isProductDeleted = true;
                }
            }

            if (isProductDeleted){
                cout << "Product Deleted Succesfully!" << endl;
            }else{
                cout << "Product Not Founded" << endl;
            }

            cout << "----------------------" << endl;

            break;

        default:
            isExited = true;
            break;
        }
    }

    system("pause");
}

// g++ main.cpp Product.cpp Warehouse.cpp -o main
// ./main.exe