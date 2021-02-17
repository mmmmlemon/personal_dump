import React from 'react';
import { StyleSheet, Alert, StatusBar } from "react-native";
import { AppLoading } from 'expo';
import { Container, Text,Title, Header, Content,Body, Subtitle, Form, Item, Input, Label, Button, Icon, Root, Right } from 'native-base';
import * as Font from 'expo-font';
import { Ionicons } from '@expo/vector-icons';
import  Calculator from './calculatorComponent';

var styles = require('./style');


export default class App extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      isReady: false,
    };
  }

  showHelp = () => {
    Alert.alert("Справка","Введите значения в поля внизу и нажмите \"Рассчитать\". \n\nНажмите \"Очистить\" чтобы очистить значения в полях.",  
    [
       { text: "Понятно" }
    ],);
  }
 

  async componentDidMount() {
    await Font.loadAsync({
      Roboto: require('native-base/Fonts/Roboto.ttf'),
      Roboto_medium: require('native-base/Fonts/Roboto_medium.ttf'),
      ...Ionicons.font,
    });
    this.setState({ isReady: true });
  }

  render() {
    if (!this.state.isReady) {
      return <AppLoading />;
    }

    return (
      <Root>
        <StatusBar barStyle="light-content" backgroundColor="#233a54"/>
        <Container style={styles.container}>
            <Header style={styles.header} noShadow androidStatusBarColor="#264263">
              <Body>
                <Title style={styles.title}>Самогон</Title>
                <Subtitle style={styles.subtitle}>Калькулятор</Subtitle>
              </Body>
              <Right>
                <Button transparent onPress={() => this.showHelp()}>
                  <Icon name='question' />
                </Button>
              </Right>
           
            </Header>
            <Content style={styles.content}>
                <Calculator></Calculator>
            </Content>
        </Container>
      </Root>
    );

    
  }
}
