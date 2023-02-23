import React from 'react';
import clsx from 'clsx';
import styles from './styles.module.css';

const FeatureList = [
  {
    title: 'Minimal API for your backend',
    description: (
      <>
        Consistent API through whole project. Only the defined API is exposed to the user. No unnecessary clutter, no distraction
      </>
    ),
  },
  {
      title: '... or  simply use in qml frontend and with additional features',
    description: (
      <>
        All APIs have QML wrappers. With the simulation you can easily start working on the frontend.
      </>
    ),
  },
  {
    title: 'Local or remote data',
    description: (
      <>
        Use a local data source or connect to a remote data source via other technology templates. Check out all the features for your technologies of choice and use your API easily with them.
      </>
    ),
  },
];

function Feature({Svg, title, description}) {
  return (
    <div className={clsx('col col--4')}>
      <div className="text--center">
      </div>
      <div className="text--center padding-horiz--md">
        <h2>{title}</h2>
        <p>{description}</p>
      </div>
    </div>
  );
}

export default function HomepageFeatures() {
  return (
    <section className={styles.features}>
      <div className="container">
        <div className="row">
          {FeatureList.map((props, idx) => (
            <Feature key={idx} {...props} />
          ))}
        </div>
      </div>
    </section>
  );
}
