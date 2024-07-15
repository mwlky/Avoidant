namespace Engine{

    class Application {
    public:
        virtual void Init() = 0;
        virtual void Render() = 0;
        virtual void Tick(double deltaTime) = 0;

        bool IsRunning() const;

    private:
        bool m_IsRunning = false;
    };
}


