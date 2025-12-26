class Solution {
public:
    int bestClosingTime(string customers) {
        int pnlty=0;
        int sn=0,sy=0;
        for(int i=0;i<customers.size();i++){
            if(customers[i]=='N')sn++;
            if(customers[i]=='Y')sy++;
        }
        pnlty=sn;
        int indx=customers.size();
        int pn=0,py=0;
        for(int i=customers.size()-1;i>=0;i--){
            if(customers[i]=='Y'){
                if(sn+py+1<=pnlty){
                    pnlty=sn+py+1;
                    indx=i;
                }
                sy--;
                py++;
                continue;
            }sn--;
            if(sn+py<=pnlty){
                pnlty=sn+py;
                indx=i;
            }
            pn++;
            
            
        }
        return indx;
    }
};