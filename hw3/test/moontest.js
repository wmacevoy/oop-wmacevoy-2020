const assert = require('assert');
const chai = require('chai');
const { Moon }  = require('../moon');

const expect = chai.expect;
const assertEq = assert.deepStrictEqual

describe('Moon', function() {
  describe('#constructor', function() {
    it('can be made', function(){
		const size = 3
        const color = "blue"
        const phase = 0
        const moon = new Moon(size, color, phase)
        assertEq(phase, moon.phase)
        assertEq(moon.color,color)
        assertEq(moon.size,size)
    });
    it('should be "Hello, Alice!" when with Alice', function(){
		// ....
    });
  });
});
