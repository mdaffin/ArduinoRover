use <spring.scad>;

union() {
    translate([30,0,0]) spring_square(fid=3, th=1.5, folds=3, lx=20, lz=6, drill=0);
    mirror([1,0,0]) translate([30,0,0]) spring_square(fid=3, th=1.5, folds=3, lx=20, lz=6, drill=0);
    translate([-45,7,-3]) cube([90, 3, 6]);
    translate([-45,-8,-3]) cube([90, 3, 6]);
}
