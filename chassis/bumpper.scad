use <spring.scad>;

union() {
    translate([30,0,0]) spring_square(fid=3, th=2, folds=3, lx=20, lz=10, drill=0);
    mirror([1,0,0]) translate([30,0,0]) spring_square(fid=3, th=2, folds=3, lx=20, lz=10, drill=0);
    translate([-45,9,-6]) cube([90, 3, 12]);
    translate([-45,-10,-6]) cube([90, 3, 12]);
}
