import posed from 'react-native-pose';
import { Animated } from 'react-native';


const FadeIn = posed.View({
    visible: { opacity: 1, transition: {duration: 350}},
    hidden: { opacity: 0, transition: {duration: 350}}
});

const FavPressed = posed.View({
    faved: {scale: 13, transition: {
        type: 'keyframes',
        ease: 'easeOut',
        values: [0, 0.7, 1.2, 1],
        duration: 200
      }},
    unfaved: {scale: 1, transition: {
        type: 'keyframes',
        ease: 'easeOut',
        values: [0, 0.7, 1.2, 1],
        duration: 200
      }},
  });

  export {FadeIn, FavPressed};