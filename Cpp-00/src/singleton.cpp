namespace project
{
    class Singleton
    {
    public:
        static Singleton &getInstance()
        {
            static Singleton instance; // Guaranteed to be destroyed. Instantiated on first use.
            return instance;
        }

    private:
        Singleton() {}

    public:
        Singleton(Singleton const &) = delete;
        void operator=(Singleton const &) = delete;
    };
}