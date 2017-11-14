void CoeurAllume (int pouls){
digitalWrite(L1,HIGH);
digitalWrite(L2,HIGH);
digitalWrite(L3,HIGH);
digitalWrite(L4,HIGH);
digitalWrite(L5,HIGH);
digitalWrite(L6,HIGH);
digitalWrite(L7,HIGH);
digitalWrite(L8,HIGH);
digitalWrite(L9,HIGH);
digitalWrite(L10,HIGH);
delay(70);
digitalWrite(L1,LOW);
digitalWrite(L2,LOW);
digitalWrite(L3,LOW);
digitalWrite(L4,LOW);
digitalWrite(L5,LOW);
digitalWrite(L6,LOW);
digitalWrite(L7,LOW);
digitalWrite(L8,LOW);
digitalWrite(L9,LOW);
digitalWrite(L10,LOW);
    

  
}
void UnsurDeux(int pouls)
digitalWrite(L1,HIGH);
digitalWrite(L3,HIGH);
digitalWrite(L5,HIGH);
digitalWrite(L7,HIGH);
digitalWrite(L9,HIGH);
delay(70);
digitalWrite(L1,LOW);
digitalWrite(L3,LOW);
digitalWrite(L5,LOW);
digitalWrite(L7,LOW);
digitalWrite(L9,LOW);
}
void UnsurTrois(int pouls)
digitalWrite(L1,HIGH);
digitalWrite(L4,HIGH);
digitalWrite(L7,HIGH);
digitalWrite(L10,HIGH);
delay(70);
digitalWrite(L1,LOW);
digitalWrite(L4,LOW);
digitalWrite(L7,LOW);
digitalWrite(L10,LOW);
}    
void Chenille(int pouls);


