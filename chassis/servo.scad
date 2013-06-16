fa=100;

module servomask() { 
  module hole(pos) {
    rotate(a=[0,90,0]) translate(pos) cylinder(r=1.75, h=20, $fn=fa/10);
  }
  module bracket() {
    translate([0,-0.75,0]) cube([5, 7.5, 21], center=true);
    translate([3,-0.75,0]) cube([1, 7.5, 2], center=true);
    hole([5,0,-9.5]);
    hole([-5,0,-9.5]);
  }
  union() {
    translate([0,10,0]) union() {
      translate([-20, -20.5, -10.5]) cube([40, 41, 21]);
      mirror([0,1,0]) translate([9.5,25,0]) bracket();
      translate([9.5,25,0]) bracket();
    }
    rotate(a=[0,90,0]) translate([0,0,20]) cylinder(r=3, h=7, $fn=fa/10);
  }
}

difference() {
  translate([0,10,0]) cube([24,55,2], center=true);
  #translate([7.5,32,-1.5]) cube([10,10,3]);
  #translate([-17.5,32,-1.5]) cube([10,10,3]);
  #translate([-2.5,32,-1.5]) cube([5,10,3]);
  #translate([7.5,-22,-1.5]) cube([10,10,3]);
  #translate([-17.5,-22,-1.5]) cube([10,10,3]);
  #translate([-2.5,-22,-1.5]) cube([5,10,3]);
  #translate([0,0,6]) rotate(a=[0,90,0]) servomask();
}

