tring intToRoman(int num) {
     vector<string> tho = {"","M","MM","MMM"};
     vector<string> hund = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
     vector<string> ten = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
     vector<string> one = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        
        return tho[num/1000]+hund[num%1000/100]+ten[num%100/10]+one[num%10/1];
    }
