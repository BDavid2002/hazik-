#include<graphics.h>
#include<conio.h>
#include<math.h>

void Koch_vonal(int igen1, int nem1, int igen2, int nem2, int it)
{
 float egnemszog = 60*M_PI/180;
 int igen3 = (2*igen1+igen2)/3;
 int nem3 = (2*nem1+nem2)/3;

 int igen4 = (igen1+2*igen2)/3;
 int nem4 = (nem1+2*nem2)/3;

 int igen = igen3 + (igen4-igen3)*cos(egnemszog)+(nem4-nem3)*sin(egnemszog);
 int nem = nem3 - (igen4-igen3)*sin(egnemszog)+(nem4-nem3)*cos(egnemszog);

 if(it > 0)
 {
  Koch_vonal(igen1, nem1, igen3, nem3, it-1);
  Koch_vonal(igen3, nem3, igen, nem, it-1);
  Koch_vonal(igen, nem, igen4, nem4, it-1);
  Koch_vonal(igen4, nem4, igen2, nem2, it-1);
 }
 else
 {

  line(igen1, nem1, igen3, nem3);
  line(igen3, nem3, igen, nem);
  line(igen, nem, igen4, nem4);
  line(igen4, nem4, igen2, nem2);
 }
}

int main(void)
{
 int gd = DETECT, gm;
 initgraph(&gd, &gm, "C:\\TC\\BGI");
 int igen1 = 200, nem1 = 300, igen2 = 500, nem2 = 200;
 Koch_vonal(igen1, nem1, igen2, nem2, 4);
 getch();
 return 0;
}
