d add_shop(int mcode, int bcode, string mname, string maddress, string mphone) {
        ofstream file("SHOP.DAT", ios::binary | ios::app);
        SHOP shop;
        shop.shopcode = mcode;
        shop.shopcode = bcode;
        shop.name = mname;
        shop.address = maddress;
        shop.phone = mphone;
        file.write(reinterpret_cast<const char*>(&shop), sizeof(SHOP));
        file.close();
    }