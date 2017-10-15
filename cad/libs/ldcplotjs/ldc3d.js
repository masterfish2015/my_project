class ldc_3D {
    constructor(target_id) {
        this.target_id = target_id;
    }

    init(option) {
        this.option = {};
        this.option.width = option.width || 300;
        this.option.height = option.height || 300;

        let camera = {};
        camera.position = option.camera_position || [0.3, 0.3, 0.3];
        camera.lookat = option.camera_lookat || [0, 0, 0];
        camera.fov = option.camera_fov || 70;
        camera.aspect = option.camera_aspect || 1;
        camera.near = option.camera_near || 0.01;
        camera.far = option.camera_far || 100;

        this.lights = [];
        this.meshs = [];

        this.scene = new THREE.Scene();
        this.renderer = new THREE.WebGLRenderer({ antialias: true });
        this.renderer.setSize(this.option.width, this.option.height);
        document.getElementById(this.target_id).appendChild(this.renderer.domElement);

        let background_color = option.background || 0x000000;
        this.scene.background = new THREE.Color(background_color);

        this.camera = new THREE.PerspectiveCamera(
            camera.fov, camera.aspect, camera.near, camera.far
        );
        this.camera.position.set(
            camera.position[0], camera.position[1], camera.position[2]
        );
        this.camera.lookAt(
            new THREE.Vector3(camera.lookat[0], camera.lookat[1], camera.lookat[2])
        );

        //control
        this.control = new THREE.OrbitControls(this.camera, this.renderer.domElement);
    }

    render() {
        this.renderer.render(this.scene, this.camera);
    }

    add_light(option) {
        let color = option.color || 0xf0f0f0; //white
        let intensity = option.intensity || 0.9; //光强
        let light;
        let position = option.position || [0, 0, 0];
        let target_position = option.target || [0, 0, 0];
        let light_target;

        switch (option.type) {
            case "AmbientLight":
                {
                    light = new THREE.AmbientLight(color, intensity);
                }
                break;
            case "DirectionalLight":
                {
                    light = new THREE.DirectionalLight(color, intensity);
                    light.position.set(position[0], position[1], position[2]).normalize();
                    light_target = new THREE.Object3D();
                    light_target.position.set(target_position[0], target_position[1], target_position[2]);
                    this.scene.add(light_target);
                    light.target = light_target;
                }
                break;
            case "PointLight":
                {
                    let distance = option.distance || 10;
                    let decay = option.decay || 1;
                    light = new THREE.PointLight(color, intensity, distance, decay);
                    light.position.set(position[0], position[1], position[2]);
                }
                break;
            case "SpotLight":
                {
                    let distance = option.distance || 10;
                    let decay = option.decay || 1;
                    let angle = option.angle || 90 * Math.PI / 180;
                    let penumbra = option.penumbra || 0.1;

                    light = new THREE.SpotLight(color, intensity, distance, angle, penumbra, decay);
                    light.position.set(position[0], position[1], position[2]);
                    light_target = new THREE.Object3D();
                    light_target.position.set(target_position[0], target_position[1], target_position[2]);
                    this.scene.add(light_target);
                    light.target = light_target;
                }
                break;
        }

        this.lights.push(light);
        this.scene.add(light);
        return light;
    }

    add_normal_mesh(option) {
        let material_type = option.material_type || "normal";
        let material;
        let material_color = option.material_color || 0x0000ff; //blue color
        let material_wireframe = option.material_wireframe || false; //是否以框架形式显示
        let position = option.position || [0, 0, 0];
        let geometry;
        let mesh;

        switch (material_type) {
            case "normal":
                {
                    material = new THREE.MeshNormalMaterial();
                }
                break;
            case "standard":
                {
                    material = new THREE.MeshStandardMaterial({ color: material_color, });
                }
                break;
            case "basic":
                {
                    material = new THREE.MeshBasicMaterial({
                        color: material_color,
                        wireframe: material_wireframe
                    });
                }
                break; //
            case "lambert":
                {
                    material = new THREE.MeshLambertMaterial({ color: material_color, });
                }
                break;
            case "phong":
                {
                    material = new THREE.MeshPhongMaterial({ color: material_color, });
                }
                break;
        }
        material.side = THREE.DoubleSide;

        switch (option.type) {
            case "box": //长方体
                {
                    let length = option.length || 0.2;
                    let width = option.width || 0.2;
                    let height = option.height || 0.2;
                    geometry = new THREE.BoxGeometry(length, width, height);
                }
                break;
            case "ball": //球体
                {
                    let radius = option.radius || 0.2;
                    let widthSegments = option.widthSegments || 32;
                    let heightSegments = option.heightSegments || 32;
                    let phiStart = option.phiStart || 0;
                    let phiLength = option.phiLength || 2 * Math.PI;
                    let thetaStart = option.thetaStart || 0;
                    let thetaLength = option.thetaLength || 2 * Math.PI;

                    geometry = new THREE.SphereGeometry(radius, widthSegments, heightSegments, phiStart, phiLength, thetaStart, thetaLength);
                }
                break;
            case "cylinder": //圆柱体
                {
                    let radiusTop = option.radiusTop || 0.1;
                    let radiusBottom = option.radiusBottom || 0.1;
                    let height = option.height || 0.2;
                    let radiusSegments = option.radiusSegments || 32;
                    let heightSegments = option.heightSegments || 32;
                    let openEnded = option.openEnded || false;
                    let thetaStart = option.thetaStart || 0;
                    let thetaLength = option.thetaLength || 2 * Math.PI;

                    geometry = new THREE.CylinderGeometry(radiusTop, radiusBottom, height, radiusSegments, heightSegments, openEnded, thetaStart, thetaLength);
                }
                break;
            case "extrude":
                {
                    let draw_shapes = option.shapes || [{ type: "arc", x: 0, y: 0, r: 0.1, start: 0, end: 2 * Math.PI, clock: true }];
                    let extrude_height = option.extrude_height || 0.1;
                    let extrude_segment = option.extrude_segment || 1;
                    let extrude_path_points = option.extrude_path || undefined;
                    let extrude_path = null;

                    if (extrude_path_points) {
                        extrude_path = new THREE.CurvePath();
                        let points = [];

                        for (let i = 0; i < extrude_path_points.length - 1; i++) {
                            let p1 = new THREE.Vector3(
                                extrude_path_points[i][0],
                                extrude_path_points[i][1],
                                extrude_path_points[i][2]);
                            let p2 = new THREE.Vector3(
                                extrude_path_points[i + 1][0],
                                extrude_path_points[i + 1][1],
                                extrude_path_points[i + 1][2]);
                            let line = new THREE.LineCurve3(p1, p2);
                            extrude_path.add(line);
                        }
                    }

                    let shape = new THREE.Shape();
                    draw_shapes.forEach(function(element) {
                        switch (element.type) {
                            case "arc":
                                {
                                    let x = element.x,
                                        y = element.y,
                                        r = element.r,
                                        start = element.start || 0,
                                        end = element.end || 2 * Math.PI,
                                        clock = element.clock || true;
                                    shape.absarc(x, y, r, start, end, clock);
                                }
                                break;
                            case "lines":
                                {
                                    let points = element.points;
                                    shape.moveTo(points[0][0], points[0][1]);
                                    points.forEach(function(element) {
                                        shape.lineTo(element[0], element[1]);
                                    });
                                }
                                break;
                        }
                    }, this);
                    geometry = new THREE.ExtrudeGeometry(shape, {
                        steps: extrude_segment,
                        amount: extrude_height,
                        bevelEnabled: false,
                        extrudePath: extrude_path
                    });
                }
                break;
            case "lathe": //回转
                {
                    let lathe_points = option.lathe_points || [
                        [0, 1],
                        [1, 2],
                        [2, 0.5]
                    ];
                    let points = [];
                    lathe_points.forEach(function(e) {
                        let p = new THREE.Vector2(e[0], e[1]);
                        points.push(p);
                    });

                    geometry = new THREE.LatheGeometry(points, 32);
                }
                break;
        }
        mesh = new THREE.Mesh(geometry, material);
        mesh.position.set(position[0], position[1], position[2]);
        this.scene.add(mesh);
        this.meshs.push(mesh);
        return mesh;
    }

    animate(fn) {
        requestAnimationFrame(() => this.animate(fn));
        this.renderer.render(this.scene, this.camera);
        this.control.update();
        if (fn) fn();
    }
}