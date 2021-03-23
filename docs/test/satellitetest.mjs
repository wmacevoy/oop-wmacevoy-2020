import { assert } from 'chai'
import { SatelliteModel } from '../satellite.mjs';

describe('Satellite', function() {
  describe('#distance()', function() {
    it('should be the initial distance', function(){
	    let distance = 3.14;
		let orbits = "earth";
	    let expect = distance;
		let sat = new SatelliteModel(distance,orbits)
	    let result = sat.distance;
	    assert.equal(expect,result);
    });
    it('should be the initial orbits', function(){
	    let distance = 3.14;
		let orbits = "earth";
	    let expect = orbits;
		let sat = new SatelliteModel(distance,orbits)
	    let result = sat.orbits;
	    assert.equal(expect,result);
    });
  });
});
