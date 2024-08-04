class ResultData{
    private:
        int ID;
        unsigned long Resulte;
        bool BetterResult;
    public:
        ResultData(int ID,unsigned long Resulte,bool BetterResult){
            this->ID = ID;
            this->BetterResult = BetterResult;
            this->Resulte = Resulte;
        }
        int GetID(){return this->ID;}
        unsigned long GetResulte() { return this->Resulte; }
        bool GetBetterResul() { return this->BetterResult; }

        void SetID(int ID) { this->ID = ID; }
        void SetResult(unsigned long Result) { this->Result = Result; }
        void SetBetterResult(bool BetterResult) { this->BetterResult = BetterResult; }
};