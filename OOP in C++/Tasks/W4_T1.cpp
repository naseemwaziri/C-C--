class Trip
{
    private:
    string name;
    date createdAt;
    string homeCurrency;
    date startsAt;
    date endsAt


    public:
    void setName(string value);
    void save();
    void delete();
};
