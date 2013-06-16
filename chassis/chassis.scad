fa = 100;
use <servo.scad>;

module microswitchmask() {
  module hole(pos) {
    translate(pos) rotate(a=[90,0,0]) cylinder(r=1, h=20, $fn=fa/10);
  }
  module leg(pos) {
    translate(pos) rotate(a=[0,90,0]) cylinder(r=0.5, h=3.5, $fn=fa/10);
  }
  union() {
    translate([-3.5,-3,-6.5]) cube([7,6,13]);
    rotate([0,10,0]) translate([-4.5,-1.5,-8]) cube([0.25,3,13]);
    hole([2,10,6.5/2]);
    hole([2,10,-6.5/2]);
    leg([3.5,0,0]);
    leg([3.5,0,-5]);
    leg([3.5,0,5]);
  }
}

module boardmask() {
  module stand(pos) {
    translate(pos) rotate(a=[0,0,0]) cylinder(r=1.5, h=50, $fn=fa/10);
  }
  union() {
    translate([-36, -23.5, -1.5]) cube([72, 47, 10]);
    stand([32,19.5,-40]);
    stand([-32,19.5,-40]);
    stand([32,-19.5,-40]);
    stand([-32,-19.9,-40]);
  }
}

module castermask() {
  module hole(pos) {
    translate(pos) cylinder(r=1, h=10, $fn=fa/7);
  }
  union() {
    difference() {
      union() {
        translate([0,0,-5]) sphere(r=9, $fn=fa/2);
        translate([0,0,-5]) cylinder(r=10, h=6, $fn=fa/2);
      }
      translate([-10,-10,0]) cube([20, 20, 10]);
    }
    hole([7,0,0]); //15mm appart
    hole([-7.5,0,0]); //15mm appart
  }
}

module wheelmask() {
  translate([-5,-45,-30]) cube([50,90,60]);
}

module base() {
  difference() {
    translate([-40, -78, 0]) cube([80,150,30]);
    translate([-37, -75, 3]) cube([73,144,30]);
    #translate([0,40,-0.5]) castermask();
    #translate([0,30,5]) boardmask();
    #translate([25,-25,14]) servomask();
    #translate([-25,-25,14]) rotate(a=[0,180,0]) servomask();
    #translate([0,0,5]) batterymask();
  }
}

module roundbase1() {
  difference() {
    cylinder(r=80, h=3, $fn=fa);
    #translate([38, 0, 14]) servomask();
    #translate([-38, 0, 14]) rotate(a=[0,180,0]) servomask();
    #translate([0, -45, 5]) boardmask();
    #translate([0, 15, 3.1]) rotate(a=[0,0,90]) batterymask();
    #translate([0, 15, 21.1]) rotate(a=[0,90,0]) lipomask();
  }
}

module servo() {
  difference() {
    union() {
      translate([4, 30.5, -13]) cube([3,10,23]);
      translate([4, -20.5, -13]) cube([3,10,23]);
    }
    #servomask();
  }
}

module battery() {
  difference() {
    union() {
      translate([-25,15,0]) cube([50,2,10]);
      translate([-5,-17,0]) cube([10,2,10]);
      translate([-30,-10,0]) cube([2,10,10]);
      translate([30,-10,0]) cube([2,10,10]);
    }
    #rotate(a=[0,0,180]) batterymask();
  }
}

module bumper() {
  module hole(pos) {
    translate(pos) rotate(a=[90,0,0]) cylinder(r=1.5, h=20, $fn=fa/7);
  }
  module hole2(pos) {
    translate(pos) rotate(a=[0,0,0]) cylinder(r=1, h=10, $fn=fa/7);
  }
  difference() {
    union() {
      translate([0,-3,11]) cube([7,5,22], center=true);
    }
    hole([0,10,5]);
    hole([0,10,12]);
  }
}

module batteryholder() {
  module lipomask() {
    translate([-18,-34,0]) cube([36,68,15]);
  }
  module batterymask() {
    union() {
      translate([-28.5,-14,1]) cube([57,28,32]);
      translate([28.5,-15,4]) cube([8,13,26]);
    }
  }
  difference() {
    cube([59,30,8], center=true);
    batterymask();
  }
}

module roundbase2() {
  difference() {
    union() {
      cylinder(r=70, h=3, $fn=fa);
      translate([21, 0, 14]) servo();
      mirror([1,0,0]) translate([21, 0, 14]) servo();
      //translate([0, -40, 3.1]) rotate(a=[0,0,0]) battery();
      translate([0,55,4]) batteryholder();
    }
    translate([10,41,-3]) cube([12,2, 10]);
    translate([-22,41,-3]) cube([12,2, 10]);
    translate([10,54,-3]) cube([12,2, 10]);
    translate([-22,54,-3]) cube([12,2, 10]);
    translate([10,67,-3]) cube([12,2, 10]);
    translate([-22,67,-3]) cube([12,2, 10]);
    //#translate([-18,54,6]) rotate(a=[90,0,-90]) microswitchmask();
    //#translate([18,54,6]) rotate(a=[-90,0,-90]) microswitchmask();
    #translate([0, 6, 30]) rotate(a=[0,0,90]) boardmask();
    translate([0, -40, 21.1]) rotate(a=[0,90,90]) lipomask();
    translate([47, 0, 10]) rotate(a=[0,0,0]) wheelmask();
    translate([-47, 0, 10]) rotate(a=[0,0,180]) wheelmask();
    translate([0, -30, -2]) castermask();
    translate([0, 30, -2]) castermask();
  }
}

//base();
//roundbase1();
roundbase2();
