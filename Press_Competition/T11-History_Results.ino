class ResultData{
    private:int ID;
    private:unsigned long Resulte;
    private:bool BetterResult;

    ResultData(int ID,unsigned long Resulte,bool BetterResult){
        this->ID = ID;
        this->BetterResult = BetterResult;
        this->Resulte = Resulte;
    }
    public:int GetID(){return this->ID;}
    public:unsigned long GetResulte() { return this->Resulte; }
    public:bool GetBetterResul() { return this->BetterResult; }
};