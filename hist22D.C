#include "TH2.h"
#include "TProfile.h"
#include "TRandom.h"
#include "TCanvas.h"
#include <iostream>

using namespace std;
void hist22D() { 


   TH2D * h2d = new TH2D("h2d","2d histogram",20,-10,5, 20, -10, 5);
   for (int i = 0; i < 100000; ++i) { 
      double u =  gRandom->Gaus(0,1);
      double w =  gRandom->Gaus(0,1);      
      double x = u; 
      double y = w + 0.6 * u;
      h2d->Fill( x,y ); 
   }

   h2d->Draw("COLZ");

   cout << "correlation factor " << h2d->GetCorrelationFactor() <<endl;

   // for second part

   TH1 * hx = h2d->ProjectionX(); 
   TH1 * px = h2d->ProfileX(); 

   TCanvas * c2 = new TCanvas("c2","c2"); 
   // divide in 2 pad in x and one in y
   c2->Divide(2,1);
   c2->cd(1); 
   hx->Draw(); 

   c2->cd(2);
   px->Draw();


}
