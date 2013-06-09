fa = 100;
module servomask() { 
  module hole(pos) {
    rotate(a=[0,90,0]) translate(pos) cylinder(r=1.75, h=20, $fn=fa/10);
  }
  union() {
    translate([-20, -20.5, -10.5]) cube([40, 41, 21]);
    translate([7,-28,-10.5]) cube([5, 56, 21]);
    hole([5,25,0]);
    hole([-5,25,0]);
    hole([5,-25,0]);
    hole([-5,-25,0]);
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
    translate(pos) rotate(a=[0,0,0]) cylinder(r=1.5, h=20, $fn=fa/10);
  }
  union() {
    translate([-36, -23.5, -1.5]) cube([72, 47, 10]);
    stand([32,19.5,-10]);
    stand([-32,19.5,-10]);
    stand([32,-19.5,-10]);
    stand([-32,-19.9,-10]);
  }
}

module test() {
  difference() {
    translate([-26/2, -28, 0]) cube([26, 63.4, 4]);
    rotate(a=[0, 90, 0]) translate([-18,0,0]) servomask();
    translate([0,32,5]) rotate(a=[90, 0, -90]) microswitchmask();
    translate([8,23,-1]) cube([10,25,6]);
    mirror([1,0,0]) translate([8,23,-1]) cube([10,25,6]);
    mirror([0,1,0]) translate([8,23,-1]) cube([10,25,6]);
    mirror([0,1,0]) mirror([1,0,0]) translate([8,23,-1]) cube([10,25,6]);
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

module batterymask() {
  translate([-18,-34,0]) cube([36,68,15]);
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

module roundbase() {
  union() {
    cylinder(r=100, h=3, $fn=fa);
    translate([21, 0, 15]) servomask();
    //translate([21, 0,0]) servomask();
  }
}

//batterymask();
//test();
//boardmask();
//servomask();
//castermask();
//base();
roundbase();
