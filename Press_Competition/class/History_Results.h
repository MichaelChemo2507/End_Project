#ifndef RESULTDATA_H
#define RESULTDATA_H

class ResultData{
    private:
        int ID;
        unsigned long Resulte;
        bool BetterResult;
    public:
        ResultData(int ID, unsigned long Resulte, bool BetterResult);
        int GetID();
        unsigned long GetResulte();
        bool GetBetterResul();

        void SetID(int ID);
        void SetResult(unsigned long Result);
        void SetBetterResult(bool BetterResult);
};
#endif 