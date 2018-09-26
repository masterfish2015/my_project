import React from 'react';
import ReactDOM from 'react-dom';

import math from 'mathjs';

const element = (
    <div>
        <h1>Hello</h1>
        <form>
            <label>length:</label>
            <input type='text'/>
        </form>
    </div>
);

ReactDOM.render( 
    element,
    document.getElementById('app')
);