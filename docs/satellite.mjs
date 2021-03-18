export class SatelliteModel {
    constructor(distance, orbits) {
        this._distance = distance;
        this._orbits = orbits;
    }
    get distance() {
        return this._distance;
    }

    get orbits() {
        return this._orbits;
    }
}