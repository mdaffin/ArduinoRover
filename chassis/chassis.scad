fa = 100;
module servomask() { 
  module hole(pos) {
    rotate(a=[0,90,0]) translate(pos) cylinder(r=1.75, h=20, $fn=fa/10);
  }
  union() {
    translate([0,10,0]) union() {
      translate([-20, -20.5, -10.5]) cube([40, 41, 21]);
      translate([7,-28,-10.5]) cube([5, 56, 21]);
      translate([12,-28,-1]) cube([1, 56, 2]);
      hole([5,25,0]);
      hole([-5,25,0]);
      hole([5,-25,0]);
      hole([-5,-25,0]);
    }
    rotate(a=[0,90,0]) translate([0,0,20]) cylinder(r=3, h=7, $fn=fa/10);
  }
}

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
    translate(pos) rotate(a=[0,0,0]) cylinder(r=1.5, h=60, $fn=fa/10);
  }
  union() {
    translate([-36, -23.5, -1.5]) cube([72, 47, 10]);
    stand([32,19.5,-50]);
    stand([-32,19.5,-50]);
    stand([32,-19.5,-50]);
    stand([-32,-19.9,-50]);
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

module lipomask() {
  translate([-18,-34,0]) cube([36,68,15]);
}
module batterymask() {
  union() {
    translate([-28.5,-14,0]) cube([57,28,32]);
    translate([28.5,-15,3]) cube([8,13,26]);
  }
}

module wheelmask() {
  translate([-5,-50,-30]) cube([50,100,60]);
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
    servomask();
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
      translate([-3.5,-19.5,20]) cube([15,19,2]);
    }
    hole([0,10,5]);
    hole([0,10,12]);
    hole2([9,-3,19]);
    hole2([9,-8,19]);
    hole2([9,-13,19]);
  }
}

module roundbase2() {
  difference() {
    union() {
      cylinder(r=60, h=3, $fn=fa);
      translate([21, 0, 14]) servo();
      mirror([1,0,0]) translate([21, 0, 14]) servo();
      translate([0, -40, 3.1]) rotate(a=[0,0,0]) battery();
      translate([30,50,2]) bumper();
      mirror([1,0,0]) translate([30,50,2]) bumper();
    }
    #translate([-18,54,6]) rotate(a=[90,0,-90]) microswitchmask();
    #translate([18,54,6]) rotate(a=[-90,0,-90]) microswitchmask();
    #translate([0, 12, 30]) rotate(a=[0,0,90]) boardmask();
    translate([0, -40, 21.1]) rotate(a=[0,90,90]) lipomask();
    translate([47, 0, 10]) rotate(a=[0,0,0]) wheelmask();
    translate([-47, 0, 10]) rotate(a=[0,0,180]) wheelmask();
    translate([0, -20, 0]) castermask();
    translate([0, -30, 0]) castermask();
    translate([0, -40, 0]) castermask();
    translate([0, 20, 0]) castermask();
    translate([0, 30, 0]) castermask();
    translate([0, 40, 0]) castermask();
  }
}

//base();
//roundbase1();
roundbase2();
