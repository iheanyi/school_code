var pad_left = function(text, width, pad) {
    if ( arguments.length < 2 || arguments.length > 3 ) {
        return "";
    }
    if ( arguments.length == 2 ) {
        pad = " ";
    }
    var result = text.toString();
    while ( result.length < width ) {
        result = pad + result;
    }
    return result;
}

var pad_right = function(text, width, pad) {
    if ( arguments.length < 2 || arguments.length > 3 ) {
        return "";
    }
    if ( arguments.length == 2 ) {
        pad = " ";
    }
    
    var result = text.toString();
    while ( result.length < width ) {
        result = result + pad;
    }
    return result;
}